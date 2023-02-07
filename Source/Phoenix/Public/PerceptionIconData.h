#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PerceptionIconData.generated.h"

class AActor;
class UBeaconInfo;
class UHUDCompassIcon;
class UPerceptionTextureCacheItem;

UCLASS(Blueprintable)
class UPerceptionIconData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* NPCCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBeaconInfo* BeaconInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHUDCompassIcon* Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPerceptionTextureCacheItem* TextureItem;
    
    UPerceptionIconData();
};

