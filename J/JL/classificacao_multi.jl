using Plots, CSV

data = CSV.File("/home/joao/Brushing-Bytes/J/JL/weather_classification_data.csv") 

t = data.Temperature
u = data.Humidity 
w = data.var"Wind Speed"
p = data.var"Precipitation (%)"
c = data.var"Cloud Cover"
a = data.var"Atmospheric Pressure"
uv = data.var"UV Index"
s = data.Season
v = data.var"Visibility (km)"
l = data.Location
wt = data.var"Weather Type"

c_d::Vector{Int16} = []
for str in c
    if str == "clear"
        push!(c_d, 0)
    elseif str == "partly cloudy"
        push!(c_d, 1)
    elseif str == "overcast"
        push!(c_d, 2)
    end
end

s_d::Vector{Int16} = []
for str in s
    if str == "Summer"
        push!(s_d, 0)
    elseif str == "Autumn"
        push!(s_d, 1)
    elseif str == "Winter"
        push!(s_d, 2)
    elseif str == "Spring"
        push!(s_d, 3)
    end
end

l_d::Vector{Int16} = []
for str in l
    if str == "mountain"
        push!(l_d, 0)
    elseif str == "inland"
        push!(l_d, 1)
    elseif str == "coastal"
        push!(l_d, 2)
    end
end

wt_d::Vector{Int16} = []
for str in wt
    if str == "Sunny"
        push!(wt_d, 0)
    elseif str == "Cloudy"
        push!(wt_d, 1)
    elseif str == "Rainy"
        push!(wt_d, 2)
    elseif str == "Snowy"
        push!(wt_d, 3)
    end
end





