#include <iostream>
#include <fstream>
#include <string>
#include "util.h"
#include "git.h"

using namespace std;

#define STRINGIFY(string) #string
#define PARSE(string) STRINGIFY(string)
#define DATA_PATH PARSE(SHARED)
#define VERSION PARSE(VER)
#define ENVIRONMENT PARSE(ENV)

string getEnv()
{
  return ENVIRONMENT;
}

string getVer()
{
  return VERSION;
}

string getDataPath()
{
  return DATA_PATH;
}

string getRootPath(string filename)
{
  string git_path = getGitPath();
  if (getEnv().compare("development") == 0)
  {
    git_path = git_path + "/dist/";
  }
  else
  {
    git_path = git_path + "/";
  }

  git_path = git_path + filename;
  return git_path;
}

void handleError(string error)
{
  cerr << "Error: " << error << endl;
  exit(1);
}

void handleInfo(string message)
{
  clog << message << endl;
}

void showHelp()
{
  string help = "Usage:\n"
                "\tkbcb command --option <argument>\n"
                "\nCommands:\n"
                "\tinit: \t\tInitiate your project on Kambria Codebase.\n"
                "\tdisconnect: \tDisconnect to Kambria Codebase (if undeclared --strict, .kambriarc will be kept).\n"
                "\tfix: \t\t(Rarely used) Resync your repository in case of critical conflicts.\n"
                "\tget-dir: \tGet directory of installed file.\n"
                "\tversion: \tShow package version (the same as --help, -h).\n"
                "\thelp: \t\tShow help information (the same as --version, -v).\n"
                "\nOptions:\n"
                "\t-r --repo: \tAdd your repository url to remote.\n"
                "\t-k --key: \tAdd authentication key to .kambriarc.\n"
                "\t--force: \tForce to init new connection without caring about remote existence.\n"
                "\t-s --strict: \tPermanently delete .kambriarc.\n"
                "\t--pre-push: \tkambria-pre-push file.\n"
                "\t-v --version: \tShow package version.\n"
                "\t-h --help: \tShow help information.";
  cout << help << endl;
  exit(0);
}

void removeLineFromFile(string line, string fpath, string ftemp)
{
  ifstream file;
  ofstream temp;
  file.open(fpath);
  temp.open(ftemp);

  string str;
  while (getline(file, str))
  {
    if (str.compare(line) != 0)
    {
      temp << str << endl;
    }
  }
  file.close();
  temp.close();
  remove(fpath.c_str());
  rename(ftemp.c_str(), fpath.c_str());
}

void setExecutable(string fpath)
{
  string cmd = "chmod +x " + fpath;
  int error;
  error = system(cmd.c_str());
  if (error != 0)
  {
    exit(1);
  }
}

bool checkEmptyExectuableFile(string fpath)
{
  ifstream file;
  file.open(fpath);

  bool isEmpty = true;
  string line;
  while (getline(file, line))
  {
    if (line.compare("#!/bin/sh") != 0 && line.compare("\0") != 0)
    {
      isEmpty = false;
    }
  }

  file.close();
  return isEmpty;
}

bool checkFileExistence(string fpath)
{
  ifstream f(fpath.c_str());
  return f.good();
}
