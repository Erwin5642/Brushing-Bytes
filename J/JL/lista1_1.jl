notasAluno = [parse(Float64, ss) for ss in split(readline())]

function mediaPonderada(notas::Vector{Float64})::Float64
    return (2 * notas[1] + 3 * notas[2] + 5 * notas[3]) / 10 
end

media = mediaPonderada(notasAluno)
println("A media do aluno foi $media")