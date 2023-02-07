#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ETransformedParameterSource.h"
#include "ETransformedParameterSpace.h"
#include "MaterialSwapParameters.h"
#include "MaterialSwapParametersSimple.h"
#include "MaterialSwapScalarParameter.h"
#include "MaterialSwapTextureParameter.h"
#include "MaterialSwapTransformedPosition.h"
#include "MaterialSwapTransformedVector.h"
#include "MaterialSwapVectorParameter.h"
#include "MaterialPermuterBlueprintLibrary.generated.h"

class AActor;

UCLASS(Blueprintable)
class MATERIALPERMUTER_API UMaterialPermuterBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UMaterialPermuterBlueprintLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void SimpleMaterialSwapParametersIsEmpty(const FMaterialSwapParametersSimple& ParameterSet, bool& bIsEmpty);
    
    UFUNCTION(BlueprintCallable)
    static FString SimpleMaterialSwapParametersDump(FMaterialSwapParametersSimple ParameterSet, const FString& Delimiter);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParametersSimple SimpleCombineMaterialSwapParameters(FMaterialSwapParametersSimple A, FMaterialSwapParametersSimple B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParametersSimple SetSimpleMaterialSwapParametersVector(UPARAM(Ref) FMaterialSwapParametersSimple& Parameters, FMaterialSwapVectorParameter Vector);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParametersSimple SetSimpleMaterialSwapParametersTexture(UPARAM(Ref) FMaterialSwapParametersSimple& Parameters, FMaterialSwapTextureParameter Texture);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParametersSimple SetSimpleMaterialSwapParametersScalar(UPARAM(Ref) FMaterialSwapParametersSimple& Parameters, FMaterialSwapScalarParameter Scalar);
    
    UFUNCTION(BlueprintCallable)
    static void SetMaterialSwapTransformedPairClosestBone(UPARAM(Ref) FMaterialSwapParameters& Parameters, AActor* Actor, FName PositionParameterName, FName VectorParameterName, FVector WorldPosition, FVector WorldVector);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParameters SetMaterialSwapParametersVector(UPARAM(Ref) FMaterialSwapParameters& Parameters, FMaterialSwapVectorParameter Vector);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParameters SetMaterialSwapParametersTransformedVector(UPARAM(Ref) FMaterialSwapParameters& Parameters, FMaterialSwapTransformedVector TransformedVector);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParameters SetMaterialSwapParametersTransformedPosition(UPARAM(Ref) FMaterialSwapParameters& Parameters, FMaterialSwapTransformedPosition TransformedPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParameters SetMaterialSwapParametersTexture(UPARAM(Ref) FMaterialSwapParameters& Parameters, FMaterialSwapTextureParameter Texture);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParameters SetMaterialSwapParametersScalar(UPARAM(Ref) FMaterialSwapParameters& Parameters, FMaterialSwapScalarParameter Scalar);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void MaterialSwapParametersIsEmpty(const FMaterialSwapParameters& ParameterSet, bool& bIsEmpty);
    
    UFUNCTION(BlueprintCallable)
    static FString MaterialSwapParametersDump(FMaterialSwapParameters ParameterSet, const FString& Delimiter);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParametersSimple MakeSimpleMaterialSwapParametersVector(FMaterialSwapVectorParameter Vector);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParametersSimple MakeSimpleMaterialSwapParametersTexture(FMaterialSwapTextureParameter Texture);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParametersSimple MakeSimpleMaterialSwapParametersScalar(FMaterialSwapScalarParameter Scalar);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParametersSimple MakeSimpleMaterialSwapParameters(TArray<FMaterialSwapScalarParameter> Scalars, TArray<FMaterialSwapVectorParameter> Vectors, TArray<FMaterialSwapTextureParameter> Textures);
    
    UFUNCTION(BlueprintCallable)
    static FMaterialSwapTransformedVector MakeMaterialSwapTransformedVectorClosestBone(AActor* Actor, FName ParameterName, FVector WorldPosition, FVector WorldVector);
    
    UFUNCTION(BlueprintCallable)
    static FMaterialSwapTransformedVector MakeMaterialSwapTransformedVector(AActor* Actor, FName ParameterName, FVector Vector, ETransformedParameterSpace Space, FName TransformSource, ETransformedParameterSource TransformType);
    
    UFUNCTION(BlueprintCallable)
    static FMaterialSwapTransformedPosition MakeMaterialSwapTransformedPositionClosestBone(AActor* Actor, FName ParameterName, FVector WorldPosition);
    
    UFUNCTION(BlueprintCallable)
    static FMaterialSwapTransformedPosition MakeMaterialSwapTransformedPosition(AActor* Actor, FName ParameterName, FVector Position, ETransformedParameterSpace Space, FName TransformSource, ETransformedParameterSource TransformType);
    
    UFUNCTION(BlueprintCallable)
    static FMaterialSwapParameters MakeMaterialSwapTransformedPairClosestBone(AActor* Actor, FName PositionParameterName, FName VectorParameterName, FVector WorldPosition, FVector WorldVector);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParameters MakeMaterialSwapParametersVector(FMaterialSwapVectorParameter Vector);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParameters MakeMaterialSwapParametersTexture(FMaterialSwapTextureParameter Texture);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParameters MakeMaterialSwapParametersScalar(FMaterialSwapScalarParameter Scalar);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParameters MakeMaterialSwapParametersFromSimple(FMaterialSwapParametersSimple Parameters);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParametersSimple MakeMaterialSwapParametersFromNotSimple(FMaterialSwapParameters Parameters);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParameters MakeMaterialSwapParameters(const TArray<FMaterialSwapScalarParameter>& Scalars, const TArray<FMaterialSwapVectorParameter>& Vectors, const TArray<FMaterialSwapTextureParameter>& Textures, const TArray<FMaterialSwapTransformedPosition>& TransformedPositions, const TArray<FMaterialSwapTransformedVector>& TransformedVectors);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParametersSimple EmptySimpleMaterialSwapParameters(UPARAM(Ref) FMaterialSwapParametersSimple& ParameterSet);
    
    UFUNCTION(BlueprintCallable)
    static FMaterialSwapParameters EmptyMaterialSwapParameters(UPARAM(Ref) FMaterialSwapParameters& ParameterSet);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParameters CombineSimpleMaterialSwapParameters(FMaterialSwapParameters A, FMaterialSwapParametersSimple B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMaterialSwapParameters CombineMaterialSwapParameters(FMaterialSwapParameters A, FMaterialSwapParameters B);
    
};

