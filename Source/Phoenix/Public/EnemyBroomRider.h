#pragma once
#include "CoreMinimal.h"
#include "Ambulatory_Character.h"
#include "SpawnSelectInfo.h"
#include "EnemyBroomRider.generated.h"

class AActor;

UCLASS(Blueprintable)
class AEnemyBroomRider : public AAmbulatory_Character {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSpawnSelectInfo> BroomRiders;
    
    AEnemyBroomRider();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FName OnOverrideCharacterLook(AActor* Actor, FName Name);
    
};

