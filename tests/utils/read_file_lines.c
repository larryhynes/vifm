#include <stic.h>

#include "../../src/utils/string_array.h"

TEST(dos_line_endings)
{
	int nlines;
	char **lines = read_file_of_lines("test-data/read/dos-line-endings", &nlines);

	assert_true(lines != NULL);
	assert_int_equal(3, nlines);
	assert_string_equal("first line", lines[0]);
	assert_string_equal("second line", lines[1]);
	assert_string_equal("third line", lines[2]);

	free_string_array(lines, nlines);
}

TEST(dos_end_of_file)
{
	int nlines;
	char **lines = read_file_of_lines("test-data/read/dos-eof", &nlines);

	assert_true(lines != NULL);
	assert_int_equal(3, nlines);
	assert_string_equal("next line contains EOF", lines[0]);
	assert_string_equal("\x1a", lines[1]);
	assert_string_equal("this is \"invisible\" line", lines[2]);

	free_string_array(lines, nlines);
}

TEST(binary_data_is_fully_read)
{
	int nlines;
	char **lines = read_file_of_lines("test-data/read/binary-data", &nlines);

	assert_true(lines != NULL);
	assert_int_equal(12, nlines);

	free_string_array(lines, nlines);
}

/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 noexpandtab cinoptions-=(0 : */
/* vim: set cinoptions+=t0 : */
