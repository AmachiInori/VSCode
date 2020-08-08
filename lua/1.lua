function sum(...)
    local result = 0;
    for i, v in ipairs{...} do
        result = result + i;
    end
    return result;
end

print(sum(1,2,3,4,5,11,6,7,8,9,100,1))
for i = 0, 5 do
    print(i)
end