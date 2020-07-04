const char *indexPage =
"<!DOCTYPE html>\n"
"<html lang=\"en\">\n"
"  <head>\n"
"    <meta charset=\"UTF-8\" />\n"
"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" />\n"
"    <title>AutoCoffee</title>\n"
"    <style>\n"
"      body {\n"
"        margin: 0;\n"
"        padding: 0;\n"
"        font-size: 1.8em;\n"
"        width: 100%;\n"
"      }\n"
"      .content {\n"
"        max-width: 90%;\n"
"        margin: auto;\n"
"      }\n"
"      .status {\n"
"        text-align: center;\n"
"        padding: 1em 0;\n"
"        margin-top: 1em;\n"
"        background-color: red;\n"
"      }\n"
"      .status.waiting {\n"
"        background-color: orange;\n"
"      }\n"
"      .status.running {\n"
"        background-color: lightgreen;\n"
"      }\n"
"      .actions {\n"
"        margin: 2em auto;\n"
"        text-align: center;\n"
"      }\n"
"      .actions button {\n"
"        font-size: 0.8em;\n"
"        width: 6em;\n"
"        height: 2em;\n"
"        margin: 0.5em 1.5em;\n"
"      }\n"
"      .timer {\n"
"        font-size: 0.6em;\n"
"        text-align: center;\n"
"      }\n"
"      .timer input {\n"
"        width: 3em;\n"
"        font-size: 1em;\n"
"      }\n"
"    </style>\n"
"  </head>\n"
"  <body>\n"
"    <div class=\"content\">\n"
"      <div class=\"status\" id=\"status-div\">\n"
"        Fetching status...\n"
"      </div>\n"
"      <div class=\"actions\">\n"
"        <button id=\"start-btn\">\n"
"          Start\n"
"        </button>\n"
"        <button id=\"stop-btn\">\n"
"          Stop\n"
"        </button>\n"
"      </div>\n"
"      <div class=\"timer\">\n"
"        <input\n"
"          type=\"number\"\n"
"          name=\"minutes\"\n"
"          id=\"minutes\"\n"
"          value=\"2\"\n"
"          min=\"0\"\n"
"          max=\"60\"\n"
"        />\n"
"        :\n"
"        <input\n"
"          type=\"number\"\n"
"          name=\"seconds\"\n"
"          id=\"seconds\"\n"
"          value=\"30\"\n"
"          min=\"0\"\n"
"          max=\"60\"\n"
"        />\n"
"      </div>\n"
"    </div>\n"
"    <script>\n"
"      let status = document.getElementById(\"status-div\");\n"
"      let start = document.getElementById(\"start-btn\");\n"
"      let stop = document.getElementById(\"stop-btn\");\n"
"      let minutes = document.getElementById(\"minutes\");\n"
"      let seconds = document.getElementById(\"seconds\");\n"
"      let timerInterval;\n"
"\n"
"      start.addEventListener(\"click\", () => {\n"
"        clearInterval(timerInterval);\n"
"        fetch(\"/on\", {\n"
"          method: \"POST\",\n"
"          headers: {\n"
"            \"Content-Type\": \"application/x-www-form-urlencoded;charset=UTF-8\",\n"
"          },\n"
"          body:\n"
"            \"minutes=\" +\n"
"            encodeURIComponent(minutes.value) +\n"
"            \"&seconds=\" +\n"
"            encodeURIComponent(seconds.value),\n"
"        });\n"
"        timerInterval = setInterval(() => {\n"
"          if (seconds.value == 0) {\n"
"            if (minutes.value == 0) clearInterval(timerInterval);\n"
"            else {\n"
"              minutes.value--;\n"
"              seconds.value = 59;\n"
"            }\n"
"          } else seconds.value--;\n"
"        }, 1000);\n"
"      });\n"
"\n"
"      stop.addEventListener(\"click\", () => {\n"
"        fetch(\"/off\", {\n"
"          method: \"POST\",\n"
"        });\n"
"        clearInterval(timerInterval);\n"
"      });\n"
"\n"
"      let checkStatus = (statusElement) => {\n"
"        fetch(\"/status\", {\n"
"          method: \"POST\",\n"
"        })\n"
"          .then((res) => res.text())\n"
"          .then((data) => {\n"
"            switch (data) {\n"
"              case \"0\":\n"
"                statusElement.classList.remove(\"running\");\n"
"                statusElement.classList.add(\"waiting\");\n"
"                statusElement.innerText = \"Waiting...\";\n"
"                break;\n"
"              case \"1\":\n"
"                statusElement.classList.remove(\"waiting\");\n"
"                statusElement.classList.add(\"running\");\n"
"                statusElement.innerText = \"Running\";\n"
"                break;\n"
"            }\n"
"          });\n"
"      };\n"
"\n"
"      setInterval(() => {\n"
"        checkStatus(status);\n"
"      }, 1000);\n"
"    </script>\n"
"  </body>\n"
"</html>\n"
;