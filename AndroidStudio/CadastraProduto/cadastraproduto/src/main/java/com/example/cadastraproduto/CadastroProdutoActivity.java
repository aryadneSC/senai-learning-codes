package com.example.cadastraproduto;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

public class CadastroProdutoActivity extends AppCompatActivity {

    private EditText editTextNome, editTextPreco;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_cadastro_produto);

        editTextNome = findViewById(R.id.editTxtNome);
        editTextPreco = findViewById(R.id.editTxtPreco);
        Button btnSalvar = findViewById(R.id.btnSalvar);

        btnSalvar.setOnClickListener(view -> {
            String nome = editTextNome.getText().toString();
            String edtPreco = editTextPreco.getText().toString();

            double preco = 0.0;
            if (!edtPreco.isEmpty()) {
                preco = Double.parseDouble(edtPreco);
            }

            Intent intent = new Intent();
            intent.putExtra("nome", nome);
            intent.putExtra("preco", preco);
            setResult(RESULT_OK, intent);
            finish();
        });
    }
}