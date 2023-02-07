#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "GameFramework/Actor.h"
#include "Templates/SubclassOf.h"
#include "RacePlatform.generated.h"

class UBroomChallengeScreen;
class UCognitionStimuliSourceComponent;

UCLASS(Blueprintable)
class ARacePlatform : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCognitionStimuliSourceComponent* CognitionStimuliSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo RaceId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UBroomChallengeScreen> RaceWidgetClass;
    
public:
    ARacePlatform();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPlatformUnlocked();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPlatformLocked();
    
};

