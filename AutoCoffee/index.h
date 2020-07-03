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
"        height: 100vh;\n"
"      }\n"
"\n"
"      .content {\n"
"        max-width: 90%;\n"
"        margin: auto;\n"
"      }\n"
"\n"
"      .status {\n"
"        text-align: center;\n"
"        padding: 1em 0;\n"
"        margin-top: 1em;\n"
"        background-color: red;\n"
"      }\n"
"\n"
"      .status.waiting {\n"
"        background-color: orange;\n"
"      }\n"
"\n"
"      .status.running {\n"
"        background-color: lightgreen;\n"
"      }\n"
"\n"
"      .actions {\n"
"        margin: 2em auto;\n"
"        text-align: center;\n"
"      }\n"
"\n"
"      .actions button {\n"
"        font-size: 0.8em;\n"
"        width: 6em;\n"
"        height: 2em;\n"
"        margin: 0.5em 1.5em;\n"
"      }\n"
"    </style>\n"
"  </head>\n"
"  <body>\n"
"    <div class=\"content\">\n"
"      <div class=\"status\" id=\"status-div\">\n"
"        Waiting...\n"
"      </div>\n"
"      <div class=\"actions\">\n"
"        <button id=\"start-btn\">\n"
"          Start\n"
"        </button>\n"
"        <button id=\"stop-btn\">\n"
"          Stop\n"
"        </button>\n"
"      </div>\n"
"    </div>\n"
"    <script>\n"
"      let status = document.getElementById(\"status-div\");\n"
"      let start = document.getElementById(\"start-btn\");\n"
"      let stop = document.getElementById(\"stop-btn\");\n"
"\n"
"      function toggle(onoff) {\n"
"        fetch(onoff ? \"/on\" : \"/off\", {\n"
"          method: \"POST\",\n"
"        });\n"
"      }\n"
"\n"
"      start.addEventListener(\"click\", () => {\n"
"        toggle(true);\n"
"      });\n"
"\n"
"      stop.addEventListener(\"click\", () => {\n"
"        toggle(false);\n"
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