#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "MunitionType_Subsonic.h"
#include "Templates/SubclassOf.h"
#include "MunitionType_PhoenixSubsonic.generated.h"

class AActor;
class ASpellTool;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class AMunitionType_PhoenixSubsonic : public AMunitionType_Subsonic {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanOppugnoAfterProtego;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> OppugnoPhysicsObjectClass;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASpellTool* SpellTool;
    
public:
    AMunitionType_PhoenixSubsonic(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASpellTool* GetSpellTool() const;
    
    UFUNCTION(BlueprintCallable)
    void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
};

