local isInDriftMode = false

RegisterCommand("driftmode", function()
    isInDriftMode = not isInDriftMode
    local player = PlayerId()
    local vehicle = GetVehiclePedIsIn(PlayerPedId(), false)

    if isInDriftMode then
        -- Aktiviere den Drift-Modus
        SetVehicleHandlingField(vehicle, "CHandlingData", "fTractionCurveMax", 2.0)
    else
        -- Deaktiviere den Drift-Modus
        ResetHandling(vehicle)
    end
end, false)

function ResetHandling(vehicle)
    local defaultHandling = GetVehicleHandlingFloat(vehicle, "CHandlingData", "fTractionCurveMax")
    SetVehicleHandlingField(vehicle, "CHandlingData", "fTractionCurveMax", defaultHandling)
end