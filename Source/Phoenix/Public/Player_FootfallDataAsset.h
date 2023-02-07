#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Player_FootfallData.h"
#include "Player_FootfallDataAsset.generated.h"

UCLASS(Blueprintable)
class UPlayer_FootfallDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayer_FootfallData Data;
    
    UPlayer_FootfallDataAsset();
};

