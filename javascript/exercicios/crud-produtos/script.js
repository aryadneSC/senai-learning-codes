import * as api from './api.js'

const modal = document.getElementById("modal")

const nomeInput = document.getElementById("nome")
const precoInput = document.getElementById("preco")

const btnNovo = document.getElementById("btnNovo")
const btnSalvar = document.getElementById("salvar")
const btnCancelar = document.getElementById("cancelar")
const modalTitulo = document.getElementById("modalTitulo")
const listaProdutos = document.getElementById("listaProdutos")

let produtoEditando = null

function abrirModal(modo = "novo", produto = null) {
  modal.classList.remove("hidden")

  if (modo === "novo") {
    modalTitulo.innerText = "Novo Produto"
    nomeInput.value = ""
    precoInput.value = ""
    produtoEditando = null
  } else {
    modalTitulo.innerText = "Editar Produto"
    nomeInput.value = produto.nome
    precoInput.value = produto.preco
    produtoEditando = produto
  }
}

function fecharModal() {
  modal.classList.add("hidden")
}

btnNovo.addEventListener("click", () => abrirModal("novo"))
btnCancelar.addEventListener("click", fecharModal)

// 2. Criar produto
btnSalvar.addEventListener("click", async () => {
  const nome = nomeInput.value
  const preco = precoInput.value

  if (!nome || !preco) { // validar campos
    alert("Preencha todos os campos!")
    return
  }

  if (produtoEditando === null) {
    await api.criarProduto({ nome, preco })
    alert("Produto criado com sucesso!"); // Mensagem de sucesso
  } else {
    await api.atualizarProduto({ ...produtoEditando, nome, preco });
    alert("Produto atualizado com sucesso!");
  }

  fecharModal()
  await carregarProdutos()
})
//--

function criarCard(produto) {
  const card = document.createElement("div")
  card.classList.add("card")
  listaProdutos.appendChild(card)

  const titulo = document.createElement("h3")
  card.appendChild(titulo)

  titulo.innerHTML = produto.nome
  const preco = document.createElement("p")
  card.appendChild(preco)

  // Formatar preco
  preco.textContent = Number(produto.preco).toLocaleString("pt-BR", { style: "currency", currency: "BRL" })

  //----

  const divAcoes = document.createElement("div");
  divAcoes.classList.add("acoes")

  // 3. Editar Produto
  const btnEditar = document.createElement("button")
  btnEditar.classList.add("btn-primario")
  btnEditar.textContent = "Editar"
  const btnExcluir = document.createElement("button")
  btnExcluir.classList.add("btn-secundario")
  btnExcluir.textContent = "Excluir"

  btnEditar.addEventListener("click", () => abrirModal("editar", produto))

  //---

  // 4. Excluir produto

  btnExcluir.addEventListener("click", async() => {
    const confirmou = confirm("Deseja  mesmo excluir?"); // Confirmar exclusão
    if (!confirmou) 
      alert("Nenhum produto excluído!");
      return;

    await api.deletarProduto(produto.id);
    alert("Produto excluído com sucesso!");
    await carregarProdutos();
  });

  //----

  divAcoes.appendChild(btnEditar)
  divAcoes.appendChild(btnExcluir)


  card.appendChild(divAcoes)
}

// 1. Listar Produtos
async function carregarProdutos() {
  const produtos = await api.obterProdutos() // Buscar produtos da API

  listaProdutos.innerHTML = "" // Limpar lista antes de renderizar

  produtos.forEach(produto => { // Renderizar criando método criarCard
    criarCard(produto)
  })
}

carregarProdutos()