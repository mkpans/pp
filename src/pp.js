'use strict';

let fileName = "txt/brudnopis.txt";

async function loadText() {
    let pre = document.getElementById("main");
    let resp = await fetch(fileName, {cache: 'no-cache'});
    let mainElement;
    if (resp.ok) {
        let text = await resp.text();
        mainElement = document.createElement("pre");
        mainElement.append(text);
    } else {
        mainElement = document.createElement("p");
        mainElement.append(`Nie udało się załadować brudnopisu!`);
    }
    document.body.append(mainElement);
}
loadText();

