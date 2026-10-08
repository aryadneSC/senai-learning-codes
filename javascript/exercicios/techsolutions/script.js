function conhecerEmpresa() {
    document.getElementById('mensagem').textContent = 
    "Desenvolvemos soluções digitais para pequenas empresas que desejam crescer, melhorar seus processos e oferecer a melhor experiência para seus clientes!"

    document.getElementById('titulo-principal').style.color = "#6a4cff";

    const feedback = document.getElementById('feedback');
    feedback.textContent = "Transformando sua ideia em realidade!";
    feedback.style.color = "#6a4cff";

    alert("Boas-Vindas à Star Tech!");
}

function restaurarPagina() {
    document.getElementById('mensagem').textContent = "Estamos prontos para oferecer nossos melhores serviços para fortalecer sua empresa!";

    document.getElementById('titulo-principal').style.color = "";

    const feedback = document.getElementById('feedback');
    feedback.textContent = "Clique no botão para conhecer a Star Tech :D";
    feedback.style.color = "";
}

function mostrarServico(idMensagem, texto) {
    const mensagem = document.getElementById(idMensagem);
    mensagem.textContent = texto;
    mensagem.style.color = "#6a4cff";
    mensagem.style.fontWeight = "bold";
    alert(texto);
}

function enviarMensagem(event) {
    // Evitar o refresh da pag de resetar dados do formulário
    event.preventDefault();

    const feedback = document.getElementById('feedback-contato');
    feedback.style.color = "#00a651";
    feedback.style.fontWeight = "bold";

    alert("Mensagem enviada com sucesso!");
}

function ativarModoEscuro() {
    document.body.style.backgroundColor = "#1a1a1a";
    document.body.style.color = "#ffffff";

    document.querySelectorAll('.page-title').forEach(t => t.style.color = "#ffffff");
    document.querySelectorAll('.card').forEach(c => {
        c.style.backgroundColor = "#2a2a2a";
        c.style.borderColor = "#6a4cff";
    });
    document.querySelectorAll('.card-body p').forEach(t => t.style.color = "#dddddd");

    // VALIDAR DEPOIS!!!
    //document.querySelectorAll('.input').forEach(t => t.backgroundColor = '#333')

    const hero = document.querySelector('.hero-content');
    if (hero) hero.style.backgroundColor = "#2a2a2a";

    const form = document.querySelector('.form');
    if (form) form.style.backgroundColor = "#2a2a2a";
}

function ativarModoClaro() {
    document.body.style.backgroundColor = "";
    document.body.style.color = "";

    document.querySelectorAll('.page-title').forEach(t => t.style.color = "");
    document.querySelectorAll('.card').forEach(c => {
        c.style.backgroundColor = "";
        c.style.borderColor = "";
    });
    document.querySelectorAll('.card-body p').forEach(t => t.style.color = "");

    const hero = document.querySelector('.hero-content');
    if (hero) hero.style.backgroundColor = "";

    const form = document.querySelector('.form');
    if (form) form.style.backgroundColor = "";
}