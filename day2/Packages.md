# Установка необходимых пакетов в виртуальную машину

## Текстовый редактор

В качестве текстового редактора будет использоваться Visual Studio Code. Для его установки в Ubuntu следует [получить .deb пакет](https://code.visualstudio.com/sha/download?build=stable&os=linux-deb-x64) и ввести 

```console
sudo apt install ./<file>.deb
```

где `<file>` - имя скаченного файла. Полная инструкция доступна на [официальном сайте](https://code.visualstudio.com/docs/setup/linux)

## Менеджер пакетов и система управления средой miniconda

Инструкция по установке доступна на [на официальном сайте](https://docs.anaconda.com/free/miniconda/)

Для установке необходимо ввести

```console
mkdir -p ~/miniconda3
wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh -O ~/miniconda3/miniconda.sh
bash ~/miniconda3/miniconda.sh -b -u -p ~/miniconda3
rm -rf ~/miniconda3/miniconda.sh

~/miniconda3/bin/conda init bash
```

[Настройка прокси](https://docs.anaconda.com/free/working-with-conda/configurations/proxy/)

## Работа с conda

Создание окружения

```console
conda create --name myenv python=3.11
```

Активация окружения

```console
conda activate myenv
```

## Установка TensorFlow

```console
pip install tensorflow
```