#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2017, Data61, CSIRO (ABN 41 687 119 230)
#
# SPDX-License-Identifier: BSD-2-Clause
#

'''
Script for parsing and Isabelle's internal symbols definition and outputing a
mapping to unicode.

The expected parameter to the --input command line argument is the 'symbols'
file, currently at ~~/etc/symbols.
'''

from __future__ import absolute_import, division, print_function, \
    unicode_literals

import argparse, codecs, six, sys

HEADER = '''#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2017, Data61, CSIRO (ABN 41 687 119 230)
#
# SPDX-License-Identifier: BSD-2-Clause
#

# THIS FILE WAS GENERATED BY make_isabelle_symbols.py.

from __future__ import absolute_import, division, print_function, \\
    unicode_literals
from camkes.internal.seven import cmp, filter, map, zip

'''

def main(argv):
    parser = argparse.ArgumentParser(
        description='parse the Isabelle symbols file into Python')
    parser.add_argument('--input', '-i', type=argparse.FileType('r'),
        required=True, help='Isabelle symbols file to read')
    parser.add_argument('--output', '-o', type=argparse.FileType('w'),
        default=open('/dev/stdout', 'wt'), help='File to write results to')
    options = parser.parse_args(argv[1:])

    # Re-open the output as UTF-8.
    options.output = codecs.open(options.output.name, 'w', 'utf-8')

    options.output.write(HEADER)
    options.output.write('ISABELLE_SYMBOLS = frozenset((\n')

    for number, line in enumerate(x.strip() for x in options.input):

        if line.startswith('#'):
            # Comment
            continue

        if line == '':
            # Blank line.
            continue

        fields = line.split()
        if len(fields) < 3 or len(fields) % 2 == 0:
            sys.stderr.write('unexpected format of line %d\n' % number)
            return -1

        # Write the escape sequence for this symbol.
        options.output.write('    (\'%s\', ' % fields[0].replace('\\', '\\\\'))

        for k, v in zip(*[iter(fields[1:])] * 2):
            if k == 'code:':
                try:
                    code = int(v, 16)
                except ValueError:
                    sys.stderr.write('invalid code field on line %d\n' %
                        number)
                    return -1

                # Write the unicode for this symbol.
                options.output.write('\'%s\'),\n' % six.unichr(code))
                break
        else:
            sys.stderr.write('no code field on line %d\n' % number)
            return -1

    options.output.write('))')

    return 0

if __name__ == '__main__':
    sys.exit(main(sys.argv))
