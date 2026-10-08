alert('Clique no botão para conhecer nossa empresa.');

function conhecer() {
    let titulo = document.querySelector('h1');
    let msg = document.querySelector('p');
    let btn = document.querySelectorAll('button');

    alert('A TechWeb desenvolve soluções digitais para empresas.');
    
    titulo.style.color = "#52796F";
    titulo.textContent = "Obrigada pela visita!";
    document.body.style.backgroundColor = "#1a1a1a";
    msg.style.color = "#bbbaba";
    alert('Estilo Alterado!')
}