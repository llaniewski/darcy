AddField(name = "pres", dx = c(-1, 1), dy = c(-1, 1))
AddField(name = "darcy", dx = c(-1, 1), dy = c(-1, 1))
AddDensity(name = "darcy")

AddQuantity(name = "P")

AddSetting(name = "Relaxation")

AddSetting(name = "Darcy", zonal = TRUE)
AddSetting(name = "Pressure", zonal = TRUE)

AddNodeType(name = "Dirichlet", group = "BOUNDARY")
