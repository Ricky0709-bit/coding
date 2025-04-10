function showSet() {
    let mySet = new Set();
    mySet.add(1);
    mySet.add(2);
    mySet.add(3);
    document.getElementById("output").innerText = "Set: " + [...mySet];
}

function showMap() {
    let myMap = new Map();
    myMap.set("name", "John");
    myMap.set("age", 30);
    myMap.set("country", "USA");
    let mapEntries = Array.from(myMap.entries()).map(([key, value]) => `${key}: ${value}`).join(', ');
    document.getElementById("output").innerText = "Map: " + mapEntries;
}

function showTypeOf() {
    let result = `typeof 10: ${typeof 10}\n` +
                 `typeof 'Hello': ${typeof 'Hello'}\n` +
                 `typeof true: ${typeof true}\n` +
                 `typeof null: ${typeof null}\n` +
                 `typeof undefined: ${typeof undefined}`;
    document.getElementById("output").innerText = result;
}

function showTypeConversion() {
    let num = Number("123");
    let str = String(456);
    let bool1 = Boolean(1);
    let bool2 = Boolean(0);
    let result = `Number('123'): ${num}\n` +
                 `String(456): ${str}\n` +
                 `Boolean(1): ${bool1}\n` +
                 `Boolean(0): ${bool2}`;
    document.getElementById("output").innerText = result;
}