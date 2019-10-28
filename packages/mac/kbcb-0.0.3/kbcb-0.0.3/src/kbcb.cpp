#include <iostream>
#include <string>
#include "util.h"
#include "kambria.h"

using namespace std;

#define KBCB_BUFFER_LENGTH 255

int main(const int argc, const char *argv[])
{
  if (argc >= 2)
  {
    /**
     * Handle INIT option
     */
    string CMD(argv[1]);
    if (CMD.compare("init") == 0)
    {
      string repo = "empty";
      string key = "empty";

      // Get params by options
      for (int i = 2; i < argc; i++)
      {
        string OPT(argv[i]);
        if (OPT.compare("-r") == 0 || OPT.compare("--repo") == 0)
        {
          repo = OPT;
        }
        if (OPT.compare("-k") == 0 || OPT.compare("--key") == 0)
        {
          key = OPT;
        }
        if (OPT.compare("--force") == 0)
        {
          removeKambriaRemote();
        }
      }

      // Get params manually
      if (repo.compare("empty") == 0)
      {
        cout << "Repository URL: ";
        cin >> repo;
        repo = repo.substr(0, repo.size() - 1); // Remove newline
      }
      if (key.compare("empty") == 0)
      {
        cout << "Authentication key: ";
        cin >> key;
        key = key.substr(0, key.size() - 1); // Remove newline
      }

      // Execute params
      // Repo related
      if (repo.compare("empty") == 0 || repo.length() == 0)
      {
        string error_repo = "\tYou cannot setup Kambria Codebase without your repository url.\n"
                            "\tPlease create your repo on Kambria Codebase first.\n"
                            "\tFor more detail, access app.kambria.io";
        handleError(error_repo);
      }
      else
      {
        addHook();
        addKambriaRemote(repo);
      }
      // Key related
      if (key.compare("empty") == 0 || key.length() == 0)
      {
        string info = "You have skipped to input your key!\n"
                      "We will create a empty .kambriarc then you can edit it later.\n";
        handleInfo(info);
        createEmptyRC();
      }
      else
      {
        createRC(key);
      }
    }

    /**
     * Handle DISCONNECT option
     */
    else if (CMD.compare("disconnect") == 0)
    {
      int isStrict = 0;
      // Get params by options
      for (int i = 2; i < argc; i++)
      {
        string OPT(argv[i]);
        if (OPT.compare("-s") == 0 || OPT.compare("--strict") == 0)
        {
          isStrict = 1;
        }
      }

      if (isStrict == 1)
      {
        removeRC();
        removeHook();
      }
      else
      {
        removeHook();
      }
    }

    /**
     * Handle FIX option
     */
    else if (CMD.compare("fix") == 0)
    {
      handleError("The fix function is not implemented yet!");
    }

    /**
     * Handle GET option
     */
    else if (CMD.compare("get-dir") == 0)
    {
      // Get params by options
      for (int i = 2; i < argc; i++)
      {
        string OPT(argv[i]);
        if (OPT.compare("--pre-push") == 0)
        {
          handleInfo(getDataPath());
        }
      }
    }

    /**
     * Handle VERSION option
     */
    else if (CMD.compare("version") == 0 || CMD.compare("-v") == 0 || CMD.compare("--version") == 0)
    {
      handleInfo(getVer());
    }

    /**
     * Handle HELP option
     */
    else if (CMD.compare("help") == 0 || CMD.compare("-h") == 0 || CMD.compare("--help") == 0)
    {
      showHelp();
    }

    /**
     * Handle undefined option
     */
    else
    {
      string invalid_params = "Invalid parameters.";
      handleError(invalid_params);
    }
  }
  else
  {
    showHelp();
  }

  return 0;
}
