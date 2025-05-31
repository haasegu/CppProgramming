# Getting started with github classroom - students edition

This guide will help you to set up github classroom and a github codespace for the course.
This guide is primarly for students who haven't been in touch with git before.
If you are already familiar with git, you can also try to use it locally, just make sure to commit and push your code in time.

## Create a GitHub account

If you don't have an GitHub account yet, you will need to create one.
You can use that same account also in the future:
- To build a portfolio
- Collaborate on software projects
- Manage and store course works, thesis, CVs, ...

You might have already a GitLab account.
This one is not compatible since it is a different provider.

### Signup
Got to https://github.com/signup and create an account.
For the username keep in mind:
- It is permanent
- It is public
  - You might want to avoid adding personal details like your birthdate or address or political views
- You might want to show it to your future employer
  - You might want to avoid names like `poopMaster` or `sexyCoder`
- You will use/type your username frequently

## Accepting the assignemnt in GitHub classroom

For each homework, you will get a new classroom assignment.
The link will look similar to `https://classroom.github.com/a/<random-symbols>`.
Click `Accept this assignment`.
If you are currently not logged in with GitHub, please do so.
For the first assignment you might also need to allow classroom to access your github account.

Accepting the assignment creates your personal copy of the example repository inside the course.
If everything worked, you should now see:
```
You're ready to go!

You accepted the assignment, test-codespace.

Your assignment repository has been created:
https://github.com/mat-cpp/<assignment-n-yourUsername>

We've configured the repository associated with this assignment.
```

With the provided link you can access your personal repository.
In case you lose that link you can look for your repository under https://github.com/orgs/mat-cpp/repositories .

## Working on your assignment

### Codespaces

Inside your current repository (you cannot reuse the one from your previous assignment) you can start working on your code.
Click the green "<> Code" button, which opens a new menu with `Local | Codespaces`.
Select "Codespaces" and the "Create codepsace on main".
The creation of a new codespace can take up to 2 minutes.

> [!NOTE]
> The careful reader noticed the line "Codespace usage for this repository is paid for by <yourUsername>."
> "Paid" means in this context "Using your monthly contingent".
> If this contingent is used up, it will just stop working.
> Since you didn't provide any payment information, you will not be charged anything.
> Let us know, if you run out of your contingent, then we can find a solution.

When you come back in the future to this assignemnt, you can use the previously created codespace.

### Editing, Compiling, and Testing

> [!NOTE]
> You will learn in class how to edit, compile, and test your code.
> This guide mmight be expanded in the future.
> If you want, you can also expand this section.

### Saving your progress - source control

Now we want to safe your progress.
For this we use the corefunctionalitis of git.
The process is called source control and works in three steps:
1. `stage`: Select the changes you want safe.
2. `commit`: Give your changes a name and create and pack them together.
3. `push`: Send your changes from the codespace to your repository.

To access in the codespace the menu for the source control, click on the very left the symbol looking like a graph ⎇.

#### `stage`

You should now see in the source control a list of all changed files.
There select all the files you want to commit in the next step by clicking the `+` next to their names.
If you only want to add some of the changes in a single file, you can also click the filename.
A view showing the difference to the previous version opens.
There, you can `+` individual blocks of code.

#### `commit`

Now we wrap up all the selected (staged) changes.
Enter a simple meaningful commit message and click "Commit".
These messages help you (and possible other developers) to understand and find recent changes.
Ideas for messages could be `solve ex3`, `fix spelling`, `clean up`, `try fast inv sqrt`, ...

#### `push`

If you are now happy with all your changes, we need to transfer them to your repository.
For this write in the terminal `git push`.
Go back to you repository and see if the code changes.
Your last commit meesage will be shown next to the folders and files with recent changes.

> [!NOTE]
> Also all the other steps can be done from the terminal, but for this guide it felt easier to explain the interface.

### Automatic testing

We implemented a set of automatic tests, that you can see if your code would be accepted during the grading process.
It is not recommended to always use these checks in your codingworkflow.
When you feel like you finished your assignemnt, these tests can be used to check for some common mistakes.
Also, if your code passes these tests it is not guarnteed that you will receive 100% of the points.
However, when the tests fail, it is very likely that you will receive 0 points for all failing problems.

The tests run everytime you `push` the code.
In your repository, you can go to the tab `▶️ Actions`.
There, you have the list of all automated tests that were run on your code in the past.
Each entry is from a different state of your repository.
Selecting the newest test gives you more insight in which problems of the assignment already pass and which need some reworking.

