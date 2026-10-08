function enviarMensagem(event) {
    // Evitar o refresh da pag de resetar dados do formulário
    event.preventDefault();

    const feedback = document.getElementById('feedback-contato');
    feedback.style.color = "#00a651";
    feedback.style.fontWeight = "bold";

    alert("Mensagem enviada com sucesso!");
}