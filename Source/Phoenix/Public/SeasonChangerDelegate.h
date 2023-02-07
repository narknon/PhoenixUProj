#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ESeasonOverride.h"
#include "SeasonChangerDelegate.generated.h"

UCLASS(Blueprintable)
class ASeasonChangerDelegate : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DisableSeasonChanges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESeasonOverride SeasonOverride;
    
    ASeasonChangerDelegate();
};

