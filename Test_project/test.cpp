#include "pch.h"
#include "../Analyze/threadPools.hpp"
#include "../Analyze/main.cpp"

threadPools pools(std::thread::hardware_concurrency());

std::string goodPath = R"(C:\Users\Adrian\Documents\Nowyfolder)";
std::string wrongPath = R"(C:\Nowhere\to\go)";

TEST(EmptyTaskShouldReturn0, empty)
{
	ASSERT_TRUE(pools.get_tasks() == 0);
}

TEST(GivenTaskShouldHaveOccurence, occurence)
{
	listFilesWithThreads(goodPath);

	int total = pools.get_tasks();

	ASSERT_TRUE(total > 0);
}

TEST(ValidPathWithDirectoryShouldHaveFilledCounter, filled_counter)
{
	countStats(goodPath);
	
	ASSERT_TRUE(nrOf.howManyDirectories > 0);
}

TEST(ValidPathWithFileShouldHaveFilledCounter, filled_file)
{
	countStats(goodPath);

	ASSERT_TRUE(nrOf.howManyFiles > 0);
}

TEST(ValidPathWithEmptyLineShouldHaveFilledCounter, filled_line)
{
	countStats(goodPath);

	ASSERT_TRUE(nrOf.emptyLines > 0);
}

TEST(ValidPathWithNonEmptyLineShouldHaveFilledCounter, filled_empty_line)
{
	countStats(goodPath);

	ASSERT_TRUE(nrOf.nonEmptyLines > 0);
}

TEST(NotValidPathShouldHaveEmptyCounter, empty_counter)
{

	nrOf.howManyDirectories = 0;

	countStats(wrongPath);

	ASSERT_TRUE(nrOf.howManyDirectories == 0);
}

TEST(ValidPathShouldListDirs, valid_dir)
{
	listFilesWithThreads(goodPath);

	ASSERT_TRUE(nrOf.nonEmptyLines > 0);
}

TEST(NotValidPathShouldNotListDirs)
{
	nrOf.nonEmptyLines = 0;

	countStats(wrongPath);

	ASSERT_TRUE(nrOf.nonEmptyLines = 0);
}







