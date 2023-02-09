#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Templates/SubclassOf.h"
#include "TransfigurationSpawnController.generated.h"

class ATransfigurationPreviewActor;

UCLASS(Blueprintable)
class UTransfigurationSpawnController : public UTickableWorldSubsystem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ATransfigurationPreviewActor> PreviewActorClass;

    //~ Begin FTickableGameObject Interface
    virtual void Tick(float DeltaTime) override;
    virtual bool IsTickable() const override;
    virtual TStatId GetStatId() const override;
    //~ End FTickableGameObject Interface
    
public:
    UTransfigurationSpawnController();
};

