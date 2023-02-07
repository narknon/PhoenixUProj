#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "OverlapEffectsClothingDataAsset.generated.h"

UCLASS(Blueprintable)
class FXUTIL_API UOverlapEffectsClothingDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> TightNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> LooseNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> CapeOrRobeNames;
    
    UOverlapEffectsClothingDataAsset();
};

