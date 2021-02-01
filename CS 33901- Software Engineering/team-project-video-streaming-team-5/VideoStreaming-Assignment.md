
# Video Streaming Team Project

This is a summary of the assignment.  See the course web page for complete details.

Your company is purchasing a streaming video service. The plan is to use the supplied code (and associated data-mining platform) for a future software product. 

Your team has been put in charge of the software. The immediate goal is to bring this codebase up to company development standards by creating test cases and performing refactoring. You will not be adding any new features, or change the behavior of the code in any way, only improve the design and implementation quality of the current functionality.

Each team will have a GitHub Classroom repository.  ALL work will be through the project repository via issues, branches, and pull requests. Discussions will take place via the issues tracking system in GitHub

Tasks you need to complete:

* **Create a class diagram of the system**.  Create a class diagram of the system.  Make sure each class is included and the relationships between classes documented.  Store a PDF of the diagram in the repository.  Name it ClassDiagram-Orginal.pdf.

* **Create test cases for each system feature**.  Create an issue in the repository for each set of test cases. Then, assign them to a member of the team. Note that before you perform any refactoring on a class, you will need a complete set of test cases.  You will be using the Catch2 unit testing framework.   Documentation and a tutorial are at https://github.com/catchorg/Catch2.   This is already set up in the project.

* **Perform Refactorings** Contribute  refactorings by creating issues in the repository. These issues must give a motivation for why the refactoring is necessary, and include the name of the refactoring.   There will be a list of refactoring to perform.

* **Create a class diagram of the final system**.  After all the refactoring is complete create a new class diagram of the system that is an updated version of the original.   Store a PDF of the diagram in the repository.  Name it ClassDiagram-Final.pdf.  Note it may be easier update your class diagram after each refactoring.


For each of these activities:

* Team members will assign themselves issues from the team repository
* For each issue, a topic branch will be created with the number of the issue, e.g., *issue1*. Work for that issue will occur on that branch.
* Work from the branch will be contributed to the master branch via pull requests. No direct work will occur on the code in the master branch.
* Issues must be closed if the refactoring is performed and the changes have been pulled into the master branch. Issues can also be closed if the team decides the refactoring is not a good idea.
* Note that if the refactoring causes methods to be created or removed, the unit test may also need refactoring
* The current coding style (indentation, use of whitespace, etc) in the existing code meets the company coding standard, and is to be preserved in any changes that are made

Notes:

* The person who creates an issue does not have to be the same as the person who performs the changes
* As much as possible, discussion on technical issues must be through the issue tracking system of GitHub.  If you discuss it via voice or chat summarize the discussion in Issues.
* Your score on this assignment depends on your contribution, including creating issues and performing refactorings. Therefore, use your own GitHub account to contribute issues, contribute to discussions on issues, and make pull requests
* For purposes of grading, do not delete any branches

The only allowed changes to the code are:
* Addition of test cases
* Functions in the test files that allow for easier writing of test cases
* Named, Fowler refactorings. The name of the refactoring (or refactorings if there is a choice) must be used when discussing the issue
* None of the current classes can be deleted. You can add classes. 
* If you create new files, you will have to update the Makefile.
* *Points will be deducted from all members of the team for any additional functionality added to the project*

Technical Notes:
* The only branches that you can have are issue branches and master.  Changes must be pulled into the branch master to count for the project
* A Makefile is provided to build the project
* The project builds on wasp/hornet and MacOS
* The file *catch.hpp* is NOT part of the repository. The Makefile will automatically download it. If you are not using make to build your project, you will have to download this yourself. 
* Do **not** add the file *catch.hpp* to your repository. NEVER!


