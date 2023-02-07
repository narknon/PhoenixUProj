#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MIDParameters.h"
#include "MIDScalarParameter.h"
#include "MIDTextureParameter.h"
#include "MIDVectorParameter.h"
#include "MIDBlueprintLibrary.generated.h"

class AActor;
class UMaterialInstanceDynamic;
class UPrimitiveComponent;
class UTexture;

UCLASS(Blueprintable)
class MATERIALPERMUTER_API UMIDBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UMIDBlueprintLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void SetMIDParametersVector(UPARAM(Ref) FMIDParameters& Parameters, FMIDVectorParameter Vector);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void SetMIDParametersTexture(UPARAM(Ref) FMIDParameters& Parameters, FMIDTextureParameter Texture);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void SetMIDParametersScalar(UPARAM(Ref) FMIDParameters& Parameters, FMIDScalarParameter Scalar);
    
    UFUNCTION(BlueprintCallable)
    static void PrimitiveCreateMIDs(UPrimitiveComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    static void PrimitiveApplyMIDParameters(UPrimitiveComponent* Component, const FMIDParameters& Parameters, bool bAutoCreateMIDs);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void MIDParametersIsEmpty(const FMIDParameters& ParameterSet, bool& bIsEmpty);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMIDVectorParameter MakeMIDVectorParameter(FName Name, FLinearColor Vector);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMIDTextureParameter MakeMIDTextureParameter(FName Name, UTexture* Texture);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMIDScalarParameter MakeMIDScalarParameter(FName Name, float Scalar);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMIDParameters MakeMIDParametersVector(FMIDVectorParameter Vector);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMIDParameters MakeMIDParametersTexture(FMIDTextureParameter Texture);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMIDParameters MakeMIDParametersScalar(FMIDScalarParameter Scalar);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMIDParameters MakeMIDParameters(const TArray<FMIDScalarParameter>& Scalars, const TArray<FMIDVectorParameter>& Vectors, const TArray<FMIDTextureParameter>& Textures);
    
    UFUNCTION(BlueprintCallable)
    static FMIDParameters EmptyMIDParameters(FMIDParameters& ParameterSet);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMIDParameters CombineMIDParameters(FMIDParameters A, FMIDParameters B);
    
    UFUNCTION(BlueprintCallable)
    static void ApplyMIDParameters(UMaterialInstanceDynamic* Mid, const FMIDParameters& Parameters);
    
    UFUNCTION(BlueprintCallable)
    static void ActorCreateMIDs(AActor* Actor, bool bIncludeChildActors);
    
    UFUNCTION(BlueprintCallable)
    static void ActorApplyMIDParameters(AActor* Actor, const FMIDParameters& Parameters, bool bIncludeChildActors, bool bAutoCreateMIDs);
    
};

