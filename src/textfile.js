"use strict";

async function loadTextFile(element, fileName) {
    let resp = await fetch(fileName, {cache: 'no-cache'});
    if (resp.ok) {
        let text = await resp.text();
        element.textContent = text.trim();
    }
}

async function loadDataFiles() {
    let divEls = document.querySelectorAll("div[data-file]");
    for (let div of divEls) {
        let fileName = div.dataset["file"];
        let fullFileName = fileName + ".txt";
        let pre = document.createElement("pre");
        pre.className = "samp";
        loadTextFile(pre, fullFileName);
        div.append(pre);
    }
}

async function loadDataLinks()  {
    let spanEls = document.querySelectorAll("span[data-file]");
    for (let span of spanEls) {
        let fileName = span.dataset["file"];
        let fullFileName = fileName + ".txt";
        let samp = document.createElement("samp");
        samp.textContent = fullFileName;
        let a = document.createElement("a");
        a.append(samp);
        a.href = fullFileName;
        span.append(a);
    }
}

function processPreSamp() {
    let preSamp = document.querySelectorAll("pre.samp");
    for (let pre of preSamp) {
        let text = pre.innerHTML.trimEnd().split("\n");
        let indent = text[0].match(/\s*/)[0];
        pre.innerHTML = text.map(line => {
            if (line.startsWith(indent)) {
                return line.replace(indent, "");
            }
            return line;
        }).join('\n');
    }
}

loadDataLinks();
loadDataFiles();
processPreSamp();