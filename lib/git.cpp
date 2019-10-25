#include <iostream>
#include <string>
#include <unistd.h>
#include "git.h"
#include "util.h"

using namespace std;

#define GIT_BUFFER_LENGTH 8

string getGitPath()
{
  string path;

  FILE *fp;
  char reader[GIT_BUFFER_LENGTH];
  fp = popen("git rev-parse --show-toplevel", "r");
  if (fp == NULL)
  {
    const string error_fp = "Cannot recognize your repository, please make sure you are in a valid repository!";
    handleError(error_fp);
  }

  while (fgets(reader, GIT_BUFFER_LENGTH, fp) != NULL)
  {
    path = path + reader;
  }

  pclose(fp);

  if (path.size() == 0)
  {
    const string error_path = "Cannot recognize your repository, please make sure you are in a valid repository!";
    handleError(error_path);
  }

  return path.substr(0, path.size() - 1);
}

string getHookPath(const string filename)
{
  string git_path = getGitPath();
  if (getEnv().compare("development") == 0)
  {
    git_path = git_path + "/dist/";
  }
  else
  {
    git_path = git_path + "/.git/hooks/";
  }

  git_path = git_path + filename;
  return git_path;
}

bool checkHookExistence(string filename)
{
  string path = getHookPath(filename);
  if (access(path.c_str(), F_OK) != -1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void addRemote(string remote, string url)
{
  string cmd = "git remote add " + remote + " " + url;

  int error;
  error = system(cmd.c_str());
  if (error != 0)
  {
    exit(1);
  }
}

void removeRemote(string remote)
{
  string cmd = "git remote remove " + remote;

  int error;
  error = system(cmd.c_str());
  if (error != 0)
  {
    exit(1);
  }
}
