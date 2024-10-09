using CSV
using DataFrames

function text_to_csv(input::String, output::String)
    data = open(input, "r") do file
        readline(file)
    end
    rows = []
    for i in 1:3:length(data)
        row = data[i:min(i+2, end)]
        while length(row) < 3
            append!(rows, [""])
        end
        push!(rows, row)
    end

    df = DataFrame(a = [row[1] for row in rows], c = [row[2] for row in rows], d = [row[3] for row in rows])
    CSV.write(output, df)
end

a = "/home/joao/Brushing-Bytes/J/Trabalhos/AED-II/T5/tempos.txt"
b = "tempos.csv"
text_to_csv(a, b)
