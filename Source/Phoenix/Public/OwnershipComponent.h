#pragma once
#include "CoreMinimal.h"
#include "DbDoubleColumnInfo.h"
#include "Components/ActorComponent.h"
#include "SocialCapitalStatusIDs.h"
#include "OwnershipComponent.generated.h"

class AActor;
class UScheduledEntity;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UOwnershipComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbDoubleColumnInfo m_DbIdInfo[3];
    
    UOwnershipComponent();
    UFUNCTION(BlueprintCallable)
    static bool IsTakingObjectStealing(const AActor* ObjectToTake, const AActor* WhoIsTaking);
    
    UFUNCTION(BlueprintCallable)
    static bool IsEntityAnOwner(const AActor* Owned, const UScheduledEntity* ScheduledEntity);
    
    UFUNCTION(BlueprintCallable)
    static bool HasOwnership(const AActor* Owned);
    
    UFUNCTION(BlueprintCallable)
    static bool GetOwnership(const AActor* Owned, FString& o_OwnerName);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<SocialCapitalStatusIDs> GetMinimumPlayerStatusWithOwners(const AActor* OwnedObject);
    
    UFUNCTION(BlueprintCallable)
    static void CopyOwnership(const AActor* From, AActor* To);
    
};

