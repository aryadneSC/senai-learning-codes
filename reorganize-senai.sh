#!/usr/bin/env bash
# =============================================================================
# reorganize-senai.sh
# Reorganiza JAVA/SENAI para um único projeto Eclipse com pacotes padronizados.
# Uso: rode na raiz do repositório (onde fica a pasta JAVA/).
# =============================================================================

set -e  # para tudo se qualquer comando falhar

ROOT_SRC="JAVA/senai-poo/src"
PKG_ROOT="br/com/senai/aryadne"
SENAI="JAVA/SENAI"

echo "▶ Verificando que você está na raiz do repositório..."
if [ ! -d "$SENAI" ]; then
  echo "❌ Pasta JAVA/SENAI não encontrada. Rode este script na raiz do repo."
  exit 1
fi

echo "▶ Criando estrutura de destino..."
mkdir -p "$ROOT_SRC/$PKG_ROOT"

# =============================================================================
# FUNÇÃO AUXILIAR: corrige a linha 'package' dentro de um .java
# Uso: fix_package ARQUIVO "br.com.senai.aryadne.classXX"
# =============================================================================
fix_package() {
  local file="$1"
  local new_pkg="$2"
  # Remove linha package existente (se houver) e insere a nova no topo
  if grep -q "^package " "$file"; then
    sed -i "s|^package .*;|package $new_pkg;|" "$file"
  else
    # Arquivo sem package declaration: insere antes da primeira linha não-vazia/não-comentário
    sed -i "1s|^|package $new_pkg;\n\n|" "$file"
  fi
}

# =============================================================================
# AULA 02 — exercicio01..04  →  br.com.senai.aryadne.class02.activityN
# Origem: JAVA/SENAI/Aula02_Exercicios_Introducao/src/exercicioXX/
# =============================================================================
echo ""
echo "▶ Aula 02..."

for i in 01 02 03 04; do
  src_dir="$SENAI/Aula02_Exercicios_Introducao/src/exercicio$i"
  dest_dir="$ROOT_SRC/$PKG_ROOT/class02/activity$i"
  pkg="br.com.senai.aryadne.class02.activity$i"

  if [ -d "$src_dir" ]; then
    mkdir -p "$dest_dir"
    for f in "$src_dir"/*.java; do
      [ -f "$f" ] || continue
      fname=$(basename "$f")
      git mv "$f" "$dest_dir/$fname"
      fix_package "$dest_dir/$fname" "$pkg"
    done
  fi
done

# =============================================================================
# AULA 03 — classes soltas  →  br.com.senai.aryadne.class03
# Origem: JAVA/SENAI/Aula03_Exercicios_pt2/*.java
# =============================================================================
echo "▶ Aula 03..."

dest_dir="$ROOT_SRC/$PKG_ROOT/class03"
pkg="br.com.senai.aryadne.class03"
mkdir -p "$dest_dir"

for f in "$SENAI/Aula03_Exercicios_pt2"/*.java; do
  [ -f "$f" ] || continue
  fname=$(basename "$f")
  git mv "$f" "$dest_dir/$fname"
  fix_package "$dest_dir/$fname" "$pkg"
done

# =============================================================================
# AULA 04 — classes soltas + PooClass04 (Gradle)
# Soltas → br.com.senai.aryadne.class04
# PooClass04 (Person/Main) → br.com.senai.aryadne.class04.activity1
# =============================================================================
echo "▶ Aula 04..."

dest_dir="$ROOT_SRC/$PKG_ROOT/class04"
pkg="br.com.senai.aryadne.class04"
mkdir -p "$dest_dir"

for f in "$SENAI/Aula04_Exercicios_pt3"/*.java; do
  [ -f "$f" ] || continue
  fname=$(basename "$f")
  git mv "$f" "$dest_dir/$fname"
  fix_package "$dest_dir/$fname" "$pkg"
done

# PooClass04 — Person e Main
poo_src="$SENAI/Aula04_Exercicios_pt3/PooClass04/src/main/java/br/com/senai/exercises"
dest_act="$ROOT_SRC/$PKG_ROOT/class04/activity1"
pkg_act="br.com.senai.aryadne.class04.activity1"
mkdir -p "$dest_act"

if [ -d "$poo_src" ]; then
  for f in "$poo_src"/*.java; do
    [ -f "$f" ] || continue
    fname=$(basename "$f")
    git mv "$f" "$dest_act/$fname"
    fix_package "$dest_act/$fname" "$pkg_act"
  done
fi

# Remove o projeto Gradle vazio (build/, .gradle/, gradlew etc.) — não são código
echo "  ⚠ Removendo artefatos Gradle de Aula04 do git (build/, .gradle/, .jar)..."
git rm -r --cached "$SENAI/Aula04_Exercicios_pt3/PooClass04/build/" 2>/dev/null || true
git rm -r --cached "$SENAI/Aula04_Exercicios_pt3/PooClass04/.gradle/" 2>/dev/null || true
git rm -r --cached "$SENAI/Aula04_Exercicios_pt3/PooClass04/gradle/" 2>/dev/null || true
git rm --cached "$SENAI/Aula04_Exercicios_pt3/PooClass04/gradlew" 2>/dev/null || true
git rm --cached "$SENAI/Aula04_Exercicios_pt3/PooClass04/gradlew.bat" 2>/dev/null || true
git rm --cached "$SENAI/Aula04_Exercicios_pt3/PooClass04/build.gradle.kts" 2>/dev/null || true
git rm --cached "$SENAI/Aula04_Exercicios_pt3/PooClass04/settings.gradle.kts" 2>/dev/null || true
git rm --cached "$SENAI/Aula04_Exercicios_pt3/PooClass04/gradle.properties" 2>/dev/null || true

# =============================================================================
# AULA 05 — exercicio/ e lista/exercicioXX  →  br.com.senai.aryadne.class05.*
# =============================================================================
echo "▶ Aula 05..."

# exercicio/productRegistration → class05.productRegistration
src="$SENAI/Aula05/src/exercicio/productRegistration"
dest_dir="$ROOT_SRC/$PKG_ROOT/class05/productRegistration"
pkg="br.com.senai.aryadne.class05.productRegistration"
if [ -d "$src" ]; then
  mkdir -p "$dest_dir"
  for f in "$src"/*.java; do
    [ -f "$f" ] || continue
    fname=$(basename "$f")
    git mv "$f" "$dest_dir/$fname"
    fix_package "$dest_dir/$fname" "$pkg"
  done
fi

# lista/exercicioXX → class05.list.activityXX
for i in 01 02 03 04 05 06 07; do
  src="$SENAI/Aula05/src/lista/exercicio$i"
  dest_dir="$ROOT_SRC/$PKG_ROOT/class05/list/activity$i"
  pkg="br.com.senai.aryadne.class05.list.activity$i"
  if [ -d "$src" ]; then
    mkdir -p "$dest_dir"
    for f in "$src"/*.java; do
      [ -f "$f" ] || continue
      fname=$(basename "$f")
      git mv "$f" "$dest_dir/$fname"
      fix_package "$dest_dir/$fname" "$pkg"
    done
  fi
done

# lista/extra → class05.list.extra
src="$SENAI/Aula05/src/lista/extra"
dest_dir="$ROOT_SRC/$PKG_ROOT/class05/list/extra"
pkg="br.com.senai.aryadne.class05.list.extra"
if [ -d "$src" ]; then
  mkdir -p "$dest_dir"
  for f in "$src"/*.java; do
    [ -f "$f" ] || continue
    fname=$(basename "$f")
    git mv "$f" "$dest_dir/$fname"
    fix_package "$dest_dir/$fname" "$pkg"
  done
fi

# =============================================================================
# AULA 07 — já tem br.com.senai.class07 + model/  →  br.com.senai.aryadne.class07
# =============================================================================
echo "▶ Aula 07..."

src_root="$SENAI/Aula07/encapsulation_and_inheritance/src/br/com/senai/class07"
dest_root="$ROOT_SRC/$PKG_ROOT/class07"
mkdir -p "$dest_root/model"

# Main.java na raiz
for f in "$src_root"/*.java; do
  [ -f "$f" ] || continue
  fname=$(basename "$f")
  git mv "$f" "$dest_root/$fname"
  fix_package "$dest_root/$fname" "br.com.senai.aryadne.class07"
done

# model/
for f in "$src_root/model"/*.java; do
  [ -f "$f" ] || continue
  fname=$(basename "$f")
  git mv "$f" "$dest_root/model/$fname"
  fix_package "$dest_root/model/$fname" "br.com.senai.aryadne.class07.model"
done

# =============================================================================
# AULA 08 — abstractionChallenge  →  br.com.senai.aryadne.class08.model
# =============================================================================
echo "▶ Aula 08..."

src="$SENAI/Aula8/GeometricObject/src/br/com/senai/abstractionChallenge"
dest_dir="$ROOT_SRC/$PKG_ROOT/class08/model"
pkg="br.com.senai.aryadne.class08.model"
if [ -d "$src" ]; then
  mkdir -p "$dest_dir"
  for f in "$src"/*.java; do
    [ -f "$f" ] || continue
    fname=$(basename "$f")
    # Main fica em class08, não em model
    if [ "$fname" = "Main.java" ]; then
      mkdir -p "$ROOT_SRC/$PKG_ROOT/class08"
      git mv "$f" "$ROOT_SRC/$PKG_ROOT/class08/$fname"
      fix_package "$ROOT_SRC/$PKG_ROOT/class08/$fname" "br.com.senai.aryadne.class08"
    else
      git mv "$f" "$dest_dir/$fname"
      fix_package "$dest_dir/$fname" "$pkg"
    fi
  done
fi

# =============================================================================
# AULA 09 — librarySystem  →  br.com.senai.aryadne.class09.librarySystem
# =============================================================================
echo "▶ Aula 09..."

src="$SENAI/Aula09/PracticeScript/src/br/com/senai/librarySystem"
dest_dir="$ROOT_SRC/$PKG_ROOT/class09/librarySystem"
pkg="br.com.senai.aryadne.class09.librarySystem"
if [ -d "$src" ]; then
  mkdir -p "$dest_dir"
  for f in "$src"/*.java; do
    [ -f "$f" ] || continue
    fname=$(basename "$f")
    git mv "$f" "$dest_dir/$fname"
    fix_package "$dest_dir/$fname" "$pkg"
  done
fi

# =============================================================================
# MOVER java-programming-1 para fora (pasta separada na raiz, fora de JAVA/SENAI)
# Se você quiser deletar totalmente depois, basta: git rm -r JAVA/java-programming-1
# Por ora, apenas movemos para MOOC/ na raiz do repo
# =============================================================================
echo "▶ Movendo MOOC (java-programming-1) para MOOC/..."
if [ -d "JAVA/java-programming-1" ]; then
  mkdir -p "MOOC"
  git mv "JAVA/java-programming-1" "MOOC/java-programming-1"
fi

# =============================================================================
# DELETAR pastas antigas vazias do SENAI (o que sobrou após os git mv)
# =============================================================================
echo "▶ Removendo pastas antigas do SENAI do tracking do git..."
git rm -r --cached "$SENAI/Aula02_Exercicios_Introducao" 2>/dev/null || true
git rm -r --cached "$SENAI/Aula03_Exercicios_pt2" 2>/dev/null || true
git rm -r --cached "$SENAI/Aula04_Exercicios_pt3" 2>/dev/null || true
git rm -r --cached "$SENAI/Aula05" 2>/dev/null || true
git rm -r --cached "$SENAI/Aula07" 2>/dev/null || true
git rm -r --cached "$SENAI/Aula8" 2>/dev/null || true
git rm -r --cached "$SENAI/Aula09" 2>/dev/null || true

# Remove fisicamente o que sobrou (pastas vazias e arquivos não-java como module-info)
rm -rf "$SENAI/Aula02_Exercicios_Introducao" \
       "$SENAI/Aula03_Exercicios_pt2" \
       "$SENAI/Aula04_Exercicios_pt3" \
       "$SENAI/Aula05" \
       "$SENAI/Aula07" \
       "$SENAI/Aula8" \
       "$SENAI/Aula09"

# =============================================================================
# ADICIONAR .gitignore atualizado na raiz do projeto Java
# =============================================================================
echo "▶ Criando .gitignore para o projeto senai-poo..."
cat > "JAVA/senai-poo/.gitignore" << 'EOF'
# Eclipse
.classpath
.project
.settings/
bin/

# IntelliJ
.idea/
*.iml

# Gradle / Maven
build/
target/
.gradle/
*.jar
*.class

# OS
.DS_Store
Thumbs.db
EOF

git add "JAVA/senai-poo/.gitignore"

# =============================================================================
# COMMIT
# =============================================================================
echo ""
echo "▶ Fazendo commit..."
git add -A
git commit -m "refactor: reorganize SENAI Java exercises into single Eclipse project

- Merge all AulaXX folders into JAVA/senai-poo/src/br/com/senai/aryadne/
- Standardize package naming: br.com.senai.aryadne.classNN[.subpackage]
- Fix package declarations in all .java files to match new structure
- Remove Gradle build artifacts from Aula04 (build/, .gradle/, .jar)
- Move MOOC (java-programming-1) to MOOC/ folder at repo root
- Add .gitignore for Eclipse/build artifacts"

echo ""
echo "✅ Pronto! Execute 'git push origin main' para subir ao GitHub."
echo ""
echo "Estrutura gerada em JAVA/senai-poo/src/br/com/senai/aryadne/:"
find "JAVA/senai-poo/src" -name "*.java" | sort | sed 's|JAVA/senai-poo/src/br/com/senai/aryadne/||'
