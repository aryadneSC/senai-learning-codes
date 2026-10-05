function mostrarMensagem() {
    let tituloNovo = document.getElementById("title-id");
    let descNovo = document.getElementById("title-desc");

    tituloNovo.textContent = "aryadne silva campos.";
    descNovo.textContent = "Toda a sabedoria humana não vale um par de botas curtas. (Machado de Assis, provavelmente.)";

    tituloNovo.style.color = "green";
    descNovo.style.color = "black";

    alert("Achou!!");
}

function restaurar() {
    let titulo = document.getElementById("title-id");
    let desc = document.getElementById("title-desc");

    titulo.textContent = "toc toc!";
    desc.textContent = "Clique no botão para descobrir quem é!";

    titulo.style.color = "";
    desc.style.color = "";
}