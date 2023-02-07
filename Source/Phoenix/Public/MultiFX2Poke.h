#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MaterialSwapParameters.h"
#include "MultiFX2Handle.h"
#include "FXPokeNiagara.h"
#include "PokeNiagaraFXBool.h"
#include "PokeNiagaraFXColor.h"
#include "PokeNiagaraFXFloat.h"
#include "PokeNiagaraFXInt.h"
#include "PokeNiagaraFXQuat.h"
#include "PokeNiagaraFXVector.h"
#include "PokeNiagaraFXVector4.h"
#include "Templates/SubclassOf.h"
#include "MultiFX2Poke.generated.h"

class ASkinFXDefinition;

UCLASS(Blueprintable)
class UMultiFX2Poke : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UMultiFX2Poke();
    UFUNCTION(BlueprintCallable)
    static void FXPokeSkinFXVectorParameter(const FMultiFX2Handle& FXHandle, TSubclassOf<ASkinFXDefinition> FX, FName Parameter, FVector Value, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void FXPokeSkinFXScalarParameter(const FMultiFX2Handle& FXHandle, TSubclassOf<ASkinFXDefinition> FX, FName Parameter, float Value, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void FXPokeSkinFXParameters(const FMultiFX2Handle& FXHandle, TSubclassOf<ASkinFXDefinition> FX, FMaterialSwapParameters Parameters, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void FXPokeSkinFXColorParameter(const FMultiFX2Handle& FXHandle, TSubclassOf<ASkinFXDefinition> FX, FName Parameter, FLinearColor Value, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void FXPokeNiagaraVector4(const FMultiFX2Handle& FXHandle, FPokeNiagaraFXVector4 FXPoke, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void FXPokeNiagaraVector(const FMultiFX2Handle& FXHandle, FPokeNiagaraFXVector FXPoke, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void FXPokeNiagaraQuat(const FMultiFX2Handle& FXHandle, FPokeNiagaraFXQuat FXPoke, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void FXPokeNiagaraInt(const FMultiFX2Handle& FXHandle, FPokeNiagaraFXInt FXPoke, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void FXPokeNiagaraFloat(const FMultiFX2Handle& FXHandle, FPokeNiagaraFXFloat FXPoke, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void FXPokeNiagaraColor(const FMultiFX2Handle& FXHandle, FPokeNiagaraFXColor FXPoke, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void FXPokeNiagaraBool(const FMultiFX2Handle& FXHandle, FPokeNiagaraFXBool FXPoke, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void FXPokeNiagara(const FMultiFX2Handle& FXHandle, FFXPokeNiagara FXPoke, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void FXPokeMaterialSwapVectorParameter(const FMultiFX2Handle& FXHandle, FName Parameter, FVector Value, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void FXPokeMaterialSwapScalarParameter(const FMultiFX2Handle& FXHandle, FName Parameter, float Value, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void FXPokeMaterialSwapParameters(const FMultiFX2Handle& FXHandle, FMaterialSwapParameters Parameters, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void FXPokeMaterialSwapColorParameter(const FMultiFX2Handle& FXHandle, FName Parameter, FLinearColor Value, bool& bSuccess);
    
};

