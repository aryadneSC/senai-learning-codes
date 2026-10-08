function mudarEscuro() {
    document.body.style.backgroundColor = "#1a1a1a";
    document.body.style.color = "#bbbaba";

    let tituloClaro = document.querySelector('h1');
    tituloClaro.style.color = "#bbbaba";

    let msgClaro = document.querySelector('p');
    msgClaro.style.color = "#bbbaba";

    let btn = document.querySelectorAll('button');

    btn.forEach(function(btn) {
        btn.style.backgroundColor = "#1a1a1a";
        btn.style.color = "#52796F";
    });
}

function mudarClaro() {
    document.body.style.backgroundColor = "";
    document.body.style.color = "";

    let tituloEscuro = document.querySelector('h1');
    tituloEscuro.style.color = "#141414";

    let msgEscuro = document.querySelector('p');
    msgEscuro.style.color = "#141414";

    let btn = document.querySelectorAll('button');

    btn.forEach(function(btn) {
        btn.style.backgroundColor = "";
        btn.style.color = "";
    });
}