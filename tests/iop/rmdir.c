#include <stic.h>

#include <stdio.h> /* FILE fopen() fclose() */

#include <unistd.h> /* F_OK access() */

#include "../../src/compat/os.h"
#include "../../src/io/iop.h"
#include "../../src/io/ior.h"
#include "../../src/utils/fs.h"

static const char *const FILE_NAME = "file-to-remove";
static const char *const DIRECTORY_NAME = "directory-to-remove";

TEST(empty_directory_is_removed)
{
	os_mkdir(DIRECTORY_NAME, 0700);
	assert_true(is_dir(DIRECTORY_NAME));

	{
		io_args_t args =
		{
			.arg1.path = DIRECTORY_NAME,
		};
		assert_int_equal(0, iop_rmdir(&args));
	}

	assert_int_equal(-1, access(DIRECTORY_NAME, F_OK));
}

TEST(non_empty_directory_is_not_removed)
{
	os_mkdir(DIRECTORY_NAME, 0700);
	assert_true(is_dir(DIRECTORY_NAME));

	assert_int_equal(0, chdir(DIRECTORY_NAME));
	{
		FILE *const f = fopen(FILE_NAME, "w");
		fclose(f);
		assert_int_equal(0, access(FILE_NAME, F_OK));
	}
	assert_int_equal(0, chdir(".."));

	{
		io_args_t args =
		{
			.arg1.path = DIRECTORY_NAME,
		};
		assert_false(iop_rmdir(&args) == 0);
	}

	assert_true(is_dir(DIRECTORY_NAME));

	{
		io_args_t args =
		{
			.arg1.path = DIRECTORY_NAME,
		};
		assert_int_equal(0, ior_rm(&args));
	}

	assert_int_equal(-1, access(DIRECTORY_NAME, F_OK));
}

/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 noexpandtab cinoptions-=(0 : */
/* vim: set cinoptions+=t0 : */
