package com.example.cadastraproduto;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

public class CadastroProdutoActivity extends AppCompatActivity {

    private EditText editNome, editPreco;
    private Button btnSalvar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_cadastro_produto);

        editNome = findViewById(R.id.editNome);
        editPreco = findViewById(R.id.editPreco);
        btnSalvar = findViewById(R.id.btnSalvar);

        btnSalvar.setOnClickListener(v -> {
            String nome = editNome.getText().toString().trim();
            String preco = editPreco.getText().toString().trim();

            if (!nome.isEmpty() && !preco.isEmpty()) {
                Intent intent = new Intent();
                intent.putExtra("nome", nome);
                intent.putExtra("preco", preco);
                setResult(RESULT_OK, intent);
                finish();
            } else {
                // Todo: adicionar mensagem de erro
            }
        });
    }
}