#pragma once
#include "CoreMinimal.h"
#include "AvaMotionWarpingSyncPoint.h"
#include "Templates/SubclassOf.h"
#include "AvaRootMotionWarper.generated.h"

class ACharacter;
class UAvaMotionWarpWindowFinder;

USTRUCT(BlueprintType)
struct AMBULATORY_API FAvaRootMotionWarper {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UAvaMotionWarpWindowFinder>> DefaultMotionWarpWindowFinders;
    
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ACharacter> CharacterOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAvaMotionWarpWindowFinder*> MotionWarpWindowFinders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, FAvaMotionWarpingSyncPoint> SyncPoints;
    
public:
    FAvaRootMotionWarper();
};

