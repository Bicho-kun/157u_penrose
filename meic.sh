meic_all(){
  gcc main.c -o p -lm -lpng && ./p 1586d1b0.png
}

clear(){
  rm -f p 1586d1b0.png
}

gitear(){
  git init
  git add *
  git commit -m `hok`
  git branch -M main
  git remote add origin git@github.com:Bicho-kun/157u_penrose.git
  git push -u origin main
}

[ $# = 0 ] && meic_all || "$@"
