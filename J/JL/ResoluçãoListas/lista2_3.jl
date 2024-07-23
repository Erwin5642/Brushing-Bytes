mutable struct Aluno
    RGM::Int64
    Nome::String
    Email::String
    Curso::String
    Telefone::String
end

info = split(readline())
aluno = Aluno(parse(Int64, info[1]), info[2], info[3], info[4], info[5])

function infoAluno(a::Aluno)
    println("Nome: ", a.Nome)
    println("RGM: ", a.RGM)
    println("Curso: ", a.Curso)
    println("Email: ", a.Email)
    println("Telefone: ", a.Telefone)
end

infoAluno(aluno)