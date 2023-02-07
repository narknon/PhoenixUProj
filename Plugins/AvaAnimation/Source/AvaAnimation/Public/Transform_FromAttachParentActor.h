#pragma once
#include "CoreMinimal.h"
#include "TransformProvider.h"
#include "Transform_FromAttachParentActor.generated.h"

class UActorProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UTransform_FromAttachParentActor : public UTransformProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SocketName;
    
    UTransform_FromAttachParentActor();
};

