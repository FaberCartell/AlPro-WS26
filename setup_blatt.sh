#!/bin/bash

# Pfad zu deinen Templates
TEMPLATE_DIR="$HOME/Vorlagen/AlPro_Vorlagen"

# Prüfen, ob ein Name übergeben wurde
if [ -z "$1" ]; then
    echo "Fehler: Bitte einen Namen für das Blatt angeben."
    echo "Verwendung: ./setup_blatt.sh Blatt01"
    exit 1
fi

FOLDER_NAME=$1

# Prüfen, ob der Template-Ordner existiert
if [ ! -d "$TEMPLATE_DIR" ]; then
    echo "Fehler: Template-Ordner $TEMPLATE_DIR nicht gefunden!"
    echo "Bitte lege die Vorlagen zuerst dort ab."
    exit 1
fi

# Ziel-Ordner erstellen
mkdir -p "$FOLDER_NAME"

# 1. README kopieren und Platzhalter ersetzen
sed "s/{{FOLDER_NAME}}/$FOLDER_NAME/g" "$TEMPLATE_DIR/README.md.template" > "$FOLDER_NAME/README.md"

# 2. C++ Boilerplate kopieren und Platzhalter ersetzen
sed "s/{{FOLDER_NAME}}/$FOLDER_NAME/g" "$TEMPLATE_DIR/main.cpp.template" > "$FOLDER_NAME/main.cpp"

# 3. Lokales Makefile exakt so kopieren, wie es ist
cp "$TEMPLATE_DIR/Makefile.template" "$FOLDER_NAME/Makefile"

echo "✅ Setup für $FOLDER_NAME erfolgreich abgeschlossen!"
echo "📂 Dateien wurden basierend auf ~/Vorlagen/AlPro_Vorlagen generiert."