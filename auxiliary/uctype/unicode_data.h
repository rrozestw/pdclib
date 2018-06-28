/* unicode data

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#ifndef UNICODE_DATA
#define UNICODE_DATA UNICODE_DATA

#include <stdint.h>

/* https://www.unicode.org/reports/tr44/#UnicodeData.txt */

/* We do not need all these fields at this point, but we read them anyway
   so we do not need to change much should the need arise later.
*/
struct unicode_record_t
{
    uint_least32_t code_point;
    char * name;
    char general_category[ 3 ];
    int canonical_combining_class;
    char bidi_class[ 4 ];
    char * decomposition;
    int numeric_type;
    int numeric_digit;
    char * numeric_value;
    char bidi_mirrored;
    /*char * unicode_1_name;*/ /* Obsolete as of 6.2.0 */
    /*char * iso_comment;*/ /* Obsoöete as of 5.2.0 */
    uint_least32_t simple_uppercase_mapping;
    uint_least32_t simple_lowercase_mapping;
    uint_least32_t simple_titlecase_mapping;
};

struct unicode_data_t
{
    uint_least32_t size;
    struct unicode_record_t * records;
};

/* The assumed field widths, for use with check_file(). */
int const unicode_record_fields[] = {
    -1, /* code_point */
    -1, /* name */
     3, /* general_category */
    -1, /* canonical_combining_class */
     4, /* bidi_class */
    -1, /* decomposition */
    -1, /* numeric_type */
    -1, /* numeric_digit */
    -1, /* numeric_value */
     2, /* bidi_mirrored */
    -1, /* unicode_1_name */
    -1, /* iso_comment */
    -1, /* simple_uppercase_mapping */
    -1, /* simple_lowercase_mapping */
    -1  /* simple_titlecase_mapping */
};

struct unicode_data_t * read_unicode_data( const char * filename );

#endif
