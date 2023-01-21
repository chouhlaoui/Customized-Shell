# Customized Shell 

## Usage

With this Shell you can:

-  Execute commands with two modes: Batch mode and interactive mode
    
    Once you launch the program, you find a prompt waiting for you to write a file name so it can use the batch mode or a command so it can use the interactive mode.
- Use cd and all other general commands available in UNIX shell.
- Use composed Commands << cmd1 ; cmd2 >> OR << cmd1 && cmd2 >> OR << cmd1 || cmd2 >>
- Check your history and trace your command lines:
- Check the History since the day you first started using the shell by typing “history” or you can find the last commands you wrote in the current session with ↑
- Have pipe Handling
- Have error Handling
And finally, you can exit whenever you want using << quit >>

### Combination between Interactive and Batch mode 
![Why the combination is better](https://user-images.githubusercontent.com/61617827/213888923-b8c87f16-0327-4242-9901-5ce5d67ca6f7.jpeg)


## Documentation
### General Architecture

![General Architecure](https://user-images.githubusercontent.com/61617827/213888658-ebb93804-bd33-4bfb-987b-9c359b0b1170.jpg)


### Executing File Architecture

![Part Two of Executing File Architecture](https://user-images.githubusercontent.com/61617827/213888686-74479815-df04-4342-b230-a895bfba9c84.jpg)


![Part One of Executing File Architecture](https://user-images.githubusercontent.com/61617827/213888684-3299da93-a4bd-4ced-b6e6-e24903d1a4d9.jpg)




## Requirements (required)

Install gcc 

```bash
  sudo apt install gcc
  sudo apt install build-essential
```

Verify make version 

```bash
  make -version
```

Install make if you don't have it

```bash
  make -version
  sudo apt install make
```



## Run Locally


Clone the project

```bash
  git clone https://github.com/chouhlaoui/Interpreteur-De-Commande-Shell.git
```

Go to the project directory

```bash
  cd Interpreteur-De-Commande-Shell.git
```

Compile the project 
```bash
  make Compile
```

Start the program

```bash
  make Run
```

Remove the executable file

```bash
  make Reset
```

## Testing
We've added 2 bash files you can use them for tests and typical UNIX commands.








