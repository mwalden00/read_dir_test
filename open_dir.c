#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
	struct dirent *ptr_dirent;
	DIR *ptr_dir;

	struct stat st;
	stat(".", &st);

	long dir_size = st.st_size;

	ptr_dir = opendir(".");
	if (ptr_dir == NULL)
		return 1;

	char *dirs[100];
	char *files[100];
	int i = 0;
	int j = 0;
	int k;

	ptr_dirent = readdir(ptr_dir);
	while (ptr_dirent != NULL) {
		struct stat buf;
		stat(ptr_dirent->d_name, &buf);
		if (!S_ISREG(buf.st_mode)) {
			dirs[i++] = ptr_dirent->d_name;
		} else {
			files[j++] = ptr_dirent->d_name;
		}
		dir_size += buf.st_size;
		ptr_dirent = readdir(ptr_dir);
	}

	printf("%s\n", "Statistics for directory: .");
	printf("Total size of directory: %ld Bytes\n", dir_size);
	printf("Directories:\n");
	for (k = 0; k < i; k++) {
		printf("\t%s\n", dirs[k]);
	}
	printf("Files:\n");
	for (k = 0; k < j; k++) {
		printf("\t%s\n", files[k]);
	}

	closedir(ptr_dir);

	return 0;
}