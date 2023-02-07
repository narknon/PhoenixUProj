#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WorldSupportWorld.generated.h"

class ULocalPlayer;
class UWorld;
class UWorldSupportLevel;

UCLASS(Blueprintable)
class UWorldSupportWorld : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorld* World;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UWorldSupportLevel*> Levels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULocalPlayer* LocalPlayer;
    
    UWorldSupportWorld();
};

