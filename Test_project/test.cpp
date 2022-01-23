#include "pch.h"
#include "../Analyze/threadPools.hpp"
#include "../Analyze/main.cpp"

threadPools pools(std::thread::hardware_concurrency());

TEST(EmptyTaskShouldReturn0, empty)
{
	ASSERT_TRUE(pools.get_tasks() == 0);
}

TEST(GivenTaskShouldHaveOccurence, occurence)
{
	listFilesWithThreads(R"(C:\Users\Adrian\Documents\Nowyfolder)");

	int total = pools.get_tasks();

	ASSERT_TRUE(total > 0);
}

TEST(ValidPathWithDirectoryShouldHaveFilledCounter, filled_counter)
{
	countStats(R"(C:\Users\Adrian\Documents\Nowyfolder)");
	
	ASSERT_TRUE(nrOf.howManyDirectories > 0);
}

TEST(ValidPathWithFileShouldHaveFilledCounter, filled_file)
{
	countStats(R"(C:\Users\Adrian\Documents\Nowyfolder)");

	ASSERT_TRUE(nrOf.howManyFiles > 0);
}

TEST(ValidPathWithEmptyLineShouldHaveFilledCounter, filled_line)
{
	countStats(R"(C:\Users\Adrian\Documents\Nowyfolder)");

	ASSERT_TRUE(nrOf.emptyLines > 0);
}

TEST(ValidPathWithNonEmptyLineShouldHaveFilledCounter, filled_empty_line)
{
	countStats(R"(C:\Users\Adrian\Documents\Nowyfolder)");

	ASSERT_TRUE(nrOf.nonEmptyLines > 0);
}

TEST(NotValidPathShouldHaveEmptyCounter, empty_counter)
{

	nrOf.howManyDirectories = 0;

	countStats(R"(C:\Users\Adrian\Document)");

	ASSERT_TRUE(nrOf.howManyDirectories == 0);
}

TEST(ValidPathShouldListDirs, valid_dir)
{
	listFilesWithThreads(R"(C:\Users\Adrian\Documents\Nowyfolder)");

	ASSERT_TRUE(nrOf.nonEmptyLines > 0);
}

TEST(NotValidPathShouldNotListDirs)
{
	nrOf.nonEmptyLines = 0;

	countStats(R"(C:\Users\Adrian\Documents\Nowyfolder)");

	ASSERT_TRUE(nrOf.nonEmptyLines = 0);
}







