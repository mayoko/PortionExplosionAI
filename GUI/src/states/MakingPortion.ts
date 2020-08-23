import { MarbleColor } from './MarbleColor';

export enum PortionType {
    PORTION_OF_WISDOM = 'Portion of Wisdom',
    PORTION_OF_MAGNETICAL_ATTRACTION = 'Portion of Magnetical Attraction',
    ABYSSAL_DRAFT = 'Abyssal Draft',
    BALM_OF_UTTERMOST_STICKNESS = 'Balm of Uttermost Stickiness',
    ELIXIR_OF_BLIND_LOVE = 'Elixir of Blind Love',
    PORTION_OF_PRISMATIC_JOY = 'Portion of Prismatic Joy',
    SANDS_OF_TIME = 'Sands of Time',
    FILTER_OF_LAVAMANCING = 'Filter of Lavamancing',
    NONE = 'NONE',
}

export interface ColorToCount {
    color: MarbleColor;
    count: number;
}

export default interface MakingPortion {
    type: PortionType;
    colorToCounts: ColorToCount[];
}
