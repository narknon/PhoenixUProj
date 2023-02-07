#pragma once
#include "CoreMinimal.h"
#include "InteractiveObjectActor.h"
#include "TransfigurationObjectBase.generated.h"

class UCognitionStimuliSourceComponent;

UCLASS(Abstract, Blueprintable)
class PHOENIX_API ATransfigurationObjectBase : public AInteractiveObjectActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCognitionStimuliSourceComponent* CogSourceComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsPreviewActor;
    
    ATransfigurationObjectBase();
};

