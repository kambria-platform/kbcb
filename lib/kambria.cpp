#include <iostream>
#include <fstream>
#include <string>
#include "git.h"
#include "kambria.h"
#include "util.h"

using namespace std;

void copyKambriaPrePush()
{
  // Open the shared file
  ifstream input;
  cout << getDataPath() << endl;
  input.open(getDataPath());
  if (!input)
  {
    string error = "kbcb package met a critical damage, please reinstall the package and retry!";
    handleError(error);
  }
  // Create the user's file
  ofstream output;
  string hook_path = getHookPath("kambria-pre-push");
  output.open(hook_path);
  string line;
  while (getline(input, line))
  {
    output << line << endl;
  }
  input.close();
  output.close();
  setExecutable(hook_path);
}

void addExecutableCode()
{
  string hook_path = getHookPath("pre-push");
  if (checkHookExistence("pre-push") == 1)
  {
    string temp_path = getHookPath("temp-pre-push");
    removeLineFromFile("KAMBRIA_SRC_DIR=`git rev-parse --show-toplevel`", hook_path, temp_path);
    removeLineFromFile("sh $KAMBRIA_SRC_DIR/.git/hooks/kambria-pre-push $1 $2", hook_path, temp_path);
    removeLineFromFile("exit 0", hook_path, temp_path);

    string executableCode = "KAMBRIA_SRC_DIR=`git rev-parse --show-toplevel`\n"
                            "sh $KAMBRIA_SRC_DIR/.git/hooks/kambria-pre-push $1 $2\n"
                            "\n"
                            "exit 0\n";
    ofstream output;
    output.open(hook_path, ios_base::app);
    output << executableCode;
    output.close();
  }
  else
  {
    string executableCode = "#!/bin/sh\n"
                            "\n"
                            "KAMBRIA_SRC_DIR=`git rev-parse --show-toplevel`\n"
                            "sh $KAMBRIA_SRC_DIR/.git/hooks/kambria-pre-push $1 $2\n"
                            "\n"
                            "exit 0\n";
    ofstream output;
    string hook_path = getHookPath("pre-push");
    output.open(hook_path);
    output << executableCode;
    output.close();
  }

  setExecutable(hook_path);
}

void addHook()
{
  // Copy kambria-pre-hooks to user's git
  copyKambriaPrePush();
  // Add executable code to pre-push
  addExecutableCode();
}

void removeHook()
{
  // Remove kambria-pre-push
  string kambria_hook_path = getHookPath("kambria-pre-push");
  cout << "*** Removing kambria-pre-push: " << kambria_hook_path << " - ";
  if (checkHookExistence("kambria-pre-push"))
  {
    int ok = remove(kambria_hook_path.c_str());
    if (ok == 0)
    {
      cout << "Done!" << endl;
    }
    else
    {
      cout << "Error: Unnable to remove the file!" << endl;
    }
  }
  else
  {
    cout << "Done!" << endl;
  }
  // Remove pre-push
  string hook_path = getHookPath("pre-push");
  cout << "*** Removing pre-push: " << hook_path << " - ";
  if (checkHookExistence("pre-push"))
  {
    string temp_path = getHookPath("temp-pre-push");
    removeLineFromFile("KAMBRIA_SRC_DIR=`git rev-parse --show-toplevel`", hook_path, temp_path);
    removeLineFromFile("sh $KAMBRIA_SRC_DIR/.git/hooks/kambria-pre-push $1 $2", hook_path, temp_path);
    removeLineFromFile("exit 0", hook_path, temp_path);

    bool isEmpty = checkEmptyExectuableFile(hook_path);
    if (isEmpty)
    {
      int ok = remove(hook_path.c_str());
      if (ok == 0)
      {
        cout << "Done!" << endl;
      }
      else
      {
        cout << "Error: Unnable to remove the file!" << endl;
      }
    }
    else
    {
      cout << "Done!" << endl;
    }
  }
  else
  {
      cout << "Done!" << endl;
  }
}

void addKambriaRemote(string repo_url)
{
  addRemote("kambria", repo_url);
}

void removeKambriaRemote()
{
  removeRemote("kambria");
}

void createEmptyRC()
{
  string kambriarc_path = getRootPath(".kambriarc");
  ofstream kambriarc;
  kambriarc.open(kambriarc_path);
  kambriarc.close();
}

void createRC(string key)
{
  string kambriarc_path = getRootPath(".kambriarc");
  ofstream kambriarc;
  kambriarc.open(kambriarc_path);
  kambriarc << key << endl;
  kambriarc.close();
}

void removeRC()
{
  string kambriarc_path = getRootPath(".kambriarc");
  cout << "*** Removing .kambriarc: %s - " << kambriarc_path << endl;
  int ok = remove(kambriarc_path.c_str());
  if (ok == 0)
  {
    printf("Done!\n");
  }
  else
  {
    printf("Error: Unnable to remove the file!\n");
  }
}
